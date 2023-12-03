[% USE raw %]
[% USE Koha %]
[% USE AdditionalContents %]
[%- USE KohaPlugins -%]
[% USE Asset %]
[% SET opaccredits = AdditionalContents.get( location => "opaccredits", lang => lang, library => logged_in_user.branchcode || default_branch ) %]
[% PROCESS 'html_helpers.inc' %]
[% UNLESS ( is_popup ) %]
 [% SET OpacLangSelectorMode = Koha.Preference('OpacLangSelectorMode') %]
 [% IF ( opaccredits ) %]
 <div class="container-fluid">
 <div class="row">
 <div class="col">
 [% PROCESS koha_news_block news => opaccredits %]
 </div>
 </div>
 </div>
 [% END #/ opaccredits %]

 [% IF ( Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') ) || OpacKohaUrl %]
 <div class="container-fluid">
 <div class="row">
 <div class="col">
 <div id="report-koha-url">
 <div class="row justify-content-between">
 [% IF Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') %]
 <div class="col">
 <div id="report_a_problem" class="noprint">
 <a class="koha-url" href="/cgi-bin/koha/opac-reportproblem.pl">Report a problem</a>
 </div>
 </div>
 [% END # / IF Koha.Preference('OPACReportProblem') && Koha.Preference('KohaAdminEmailAddress') %]
 
 </div> <!-- /.row.justify-content-between -->
 </div> <!-- /#report-koha-url -->
 </div> <!-- /.col -->
 </div> <!-- /.row -->
 </div> <!-- /.container-fluid -->
 [% END # / OPACReportProblem || OpacKohaUrl %]
 </div> <!-- / #wrapper in masthead.inc -->

 [% IF OpacLangSelectorMode == 'both' || OpacLangSelectorMode == 'footer' %]
 [% IF ( opaclanguagesdisplay ) %]
 [% IF ( languages_loop && opaclanguagesdisplay ) %]
 [% UNLESS ( one_language_enabled ) %]
 <footer id="changelanguage"  class="noprint">
 <ul class="nav">
 <li class="nav-item">
 <span class="navbar-text">Languages:</span>
 </li>
 [% FOREACH languages_loo IN languages_loop %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.plural ) %]
 <li class="nav-item dropup">
 <a class="nav-link dropdown-toggle" href="#" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" id="show[% languages_loo.rfc4646_subtag | html %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </a><!-- /.nav-link.dropdown-toggle -->
 <div id="sub[% languages_loo.rfc4646_subtag | html %]" class="dropdown-menu" aria-labelledby="show[% languages_loo.rfc4646_subtag | html %]">
 [% FOREACH sublanguages_loo IN languages_loo.sublanguages_loop %]
 [% IF ( sublanguages_loo.enabled ) %]
 [% IF ( sublanguages_loo.sublanguage_current ) %]
 <a class="dropdown-item" href="#">[% sublanguages_loo.native_description | html %] [% sublanguages_loo.script_description | html %] [% sublanguages_loo.region_description | html %] [% sublanguages_loo.variant_description | html %] ([% sublanguages_loo.rfc4646_subtag | html %])</a>
 [% ELSE %]
 <a class="dropdown-item" href="/cgi-bin/koha/opac-changelanguage.pl?language=[% sublanguages_loo.rfc4646_subtag | uri %]"> [% sublanguages_loo.native_description | html %] [% sublanguages_loo.script_description | html %] [% sublanguages_loo.region_description | html %] [% sublanguages_loo.variant_description | html %] ([% sublanguages_loo.rfc4646_subtag | html %])</a>
 [% END %]
 [% END # / IF sublanguages_loo.enabled %]
 [% END # / FOREACH sublanguages_loo %]
 </div> <!-- /#sub[% languages_loo.rfc4646_subtag | html %] -->
 </li> <!-- /.nav-item.dropup -->
 [% ELSE %]
 [% IF ( languages_loo.group_enabled ) %]
 [% IF ( languages_loo.current ) %]
 <li class="nav-item">
 <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </a> <!-- /.nav-link -->
 </li> <!-- /.nav-item -->
 [% ELSE %]
 <li class="nav-item">
 <a class="nav-link" href="/cgi-bin/koha/opac-changelanguage.pl?language=[% languages_loo.rfc4646_subtag | uri %]">
 [% IF ( languages_loo.native_description ) %]
 [% languages_loo.native_description | html %]
 [% ELSE %]
 [% languages_loo.rfc4646_subtag | html %]
 [% END %]
 </a> <!-- /.nav-link -->
 </li> <!-- /.nav-item -->
 [% END # /IF ( languages_loo.current ) %]
 [% END # / IF languages_loo.current %]
 [% END # / IF ( languages_loo.plural ) %]
 [% END # / IF ( languages_loo.group_enabled ) %]
 [% END # / FOREACH languages_loo IN languages_loop %]
 </ul> <!-- /.nav -->
 </footer> <!-- / #changelanguage -->
 [% END # / UNLESS ( one_language_enabled ) %]
 [% END # / IF ( languages_loop && opaclanguagesdisplay ) %]
 [% END # / IF opaclanguagesdisplay %]
 [% END # /IF OpacLangSelectorMode == 'both' || OpacLangSelectorMode == 'footer' %]
[% END # / UNLESS is_popup %]

<!-- JavaScript includes -->
[% Asset.js("lib/jquery/jquery-3.6.0.min.js") | $raw %]
[% Asset.js("lib/jquery/jquery-migrate-3.3.2.min.js") | $raw %]
[% Asset.js("lib/bootstrap/js/bootstrap.bundle.min.js") | $raw %]
[% Asset.js("lib/fontfaceobserver.min.js") | $raw %]
[% Asset.js("lib/enquire.min.js") | $raw %]
<script>
    let logged_in_user_id = "[% logged_in_user.borrowernumber | html %]";
</script>
[% Asset.js("js/global.js") | $raw %]
[% IF ( OPACAmazonCoverImages || SyndeticsCoverImages ) %]
 <script>
        var NO_AMAZON_IMAGE = _("Không có ảnh bìa");
    </script>
 [% Asset.js("js/amazonimages.js") | $raw %]
[% END %]

<script>

    var MSG_CONFIRM_AGAIN = _("Cảnh báo: Hành động này không thể được khôi phục lại. Xin xác nhận lại một lần nữa")
    var MSG_DELETE_SEARCH_HISTORY = _("Bạn chắc chắn muốn xóa lịch sử tìm kiếm của mình?");
    var MSG_NO_SUGGESTION_SELECTED = _("No suggestion was selected");
    var MSG_SEARCHING = _("Đang tìm kiếm %s...");
    var MSG_ERROR_SEARCHING_COLLECTION = _("Lỗi tìm kiếm bộ sưu tập %s");
    var MSG_NO_RESULTS_FOUND_IN_COLLECTION = _("Không tìm thấy kết quả trong bộ sưu tập %s của thư viện");
    var MSG_RESULTS_FOUND_IN_COLLECTION = _("Đã tìm được %s kết quả trong bộ sưu tập %s của thư viện");
    var MSG_BY = _("Người liên quan");
    var MSG_TYPE = _("Type");
    var MSG_NEXT = _("Tiếp tục");
    var MSG_PREVIOUS = _("Sau");
    var MSG_CHECKOUTS = _("Ghi mượn");
    var MSG_NO_CHECKOUTS = _("No checkouts");
    var MSG_CHECK_OUT = _("Ghi mượn");
    var MSG_CHECK_OUT_CONFIRM = _("Are you sure you want to check out this item?");
    var MSG_CHECKED_OUT_UNTIL = _("Checked out until %s");
    var MSG_CHECK_IN = _("Ghi Trả");
    var MSG_CHECK_IN_CONFIRM = _("Are you sure you want to return this item?");
    var MSG_NO_CHECKOUTS = _("No checkouts");
    var MSG_DOWNLOAD = _("Tải báo cáo");
    var MSG_HOLDS = _("Đặt mượn");
    var MSG_NO_HOLDS = _("No holds");
    var MSG_PLACE_HOLD = _("Đặt mượn");
    var MSG_CANCEL_HOLD = _("Hủy bỏ");
    var MSG_CANCEL_HOLD_CONFIRM = _("Bạn chắc chắn muốn hủy bỏ đặt mượn này?");
    var MSG_ON_HOLD = _("Đặt mượn");

    [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) && ( Koha.Preference( 'TagsEnabled' ) == 1 ) %]
        var MSG_TAGS_DISABLED = _("Xin lỗi, các từ khóa không được kích hoạt trong hệ thống của bạn.");
        var MSG_TAG_ALL_BAD = _("Lỗi! Từ khóa của bạn chứa ký tự không phù hợp. Bạn không thể tạo từ khóa  này. Bạn vui lòng thử lại với từ khóa khác.");
        var MSG_ILLEGAL_PARAMETER = _("Lỗi! Thông số không phù hợp");
        var MSG_TAG_SCRUBBED = _("Ghi chú: Từ khóa của bạn có chứa ký tự không phù hợp nên đã bị loại bỏ. Từ khóa đã được thêm như là ");
        var MSG_ADD_TAG_FAILED = _("Error! Adding tags failed at");
        var MSG_ADD_TAG_FAILED_NOTE = _("Lưu ý: Bạn chỉ có thể thêm một từ khóa cho một tài liệu. Bạn vui lòng kiểm tra 'Từ khóa' để xem các từ khóa hiện tại của bạn.");
        var MSG_DELETE_TAG_FAILED = _("Lỗi! Bạn không thể xóa từ khóa");
        var MSG_DELETE_TAG_FAILED_NOTE = _("Lưu ý: Bạn chỉ được phép xóa các từ khóa bạn tạo ra.")
        var MSG_LOGIN_REQUIRED = _("Bạn phải đăng nhập để thêm từ khóa.");
        var MSG_TAGS_ADDED = _("Từ khóa đã nhập: ");
        var MSG_TAGS_DELETED = _("Từ khóa đã nhập: ");
        var MSG_TAGS_ERRORS = _("Lỗi: ");
        var MSG_MULTI_ADD_TAG_FAILED = _("Không thể thêm từ khóa nữa.");
        var MSG_NO_TAG_SPECIFIED = _("Không có từ khóa nào được khai báo.");
    [% END %]
    [% IF OpenLibraryCovers || OpenLibrarySearch %]
        var NO_OL_JACKET = _("Không có ảnh bìa");
    [% END %]
    [% IF (query_desc) %]
        var query_desc = "[% query_desc | html %]";
        var querystring = "[% querystring | html %]";
        var query_cgi = "[% query_cgi | html %]";
    [% END %]

    [% IF ( OPACAmazonCoverImages || SyndeticsCoverImages ) %]
        $(window).load(function() {
            verify_images();
         });
    [% END %]
    $(".print-large").on("click",function(){
        window.print();
        return false;
    });
    $(".addtoshelf").on("click",function(e){
        e.preventDefault();
        Dopop( this.href );
    });
    $("body").on("click", ".addtocart", function(e){
        e.preventDefault();
        var biblionumber = $(this).data("biblionumber");
        addRecord( biblionumber );
    });
    $("body").on("click", ".cartRemove", function(e){
        e.preventDefault();
        var biblionumber = $(this).data("biblionumber");
        delSingleRecord( biblionumber );
    });
    $(".clearsh").on("click", function(){
        return confirmDelete(MSG_DELETE_SEARCH_HISTORY);
    });

</script>

[% IF Koha.Preference( 'opacbookbag' ) == 1 %]
 [% Asset.js("js/basket.js") | $raw %]
[% ELSIF ( Koha.Preference( 'virtualshelves' ) == 1 ) %]
 [% Asset.js("js/basket.js") | $raw %]
[% ELSE %]
 <script>var readCookie;</script>
[% END %]

[% IF Koha.Preference( 'opacuserlogin' ) == 1 %][% IF Koha.Preference( 'TagsEnabled' ) == 1 %][% Asset.js("js/tags.js") | $raw %][% END %][% END %]
[% IF ( GoogleJackets ) %]
 [% Asset.js("js/google-jackets.js") | $raw %]
 <script>

        var NO_GOOGLE_JACKET = _("Không có ảnh bìa");

    </script>
[% END %]
[% IF ( Koha.Preference('OpacCoce') && Koha.Preference('CoceProviders') ) %]
 [% Asset.js("js/coce.js") | $raw %]
 <script>

        var NO_COCE_JACKET = _("Không có ảnh bìa");

    </script>
[% END %]

[% IF OPACLocalCoverImages %]
 [% Asset.js("js/localcovers.js") | $raw %]
 <script>

    var NO_LOCAL_JACKET = _("Không có ảnh bìa");

    </script>
[% END %]

[% IF ( BakerTaylorEnabled ) %]
 [% Asset.js("js/bakertaylorimages.js") | $raw %]
 <script>

        var NO_BAKERTAYLOR_IMAGE = _("Không có ảnh bìa");
        $(window).load(function(){
            bt_verify_images();
        });

    </script>
[% END %]

[% IF Koha.Preference( 'OpacNewsLibrarySelect' ) %]
<script>
    $("#news-branch-select").change(function() {
        $( "#news-branch-select" ).submit();
    });
</script>
[% END %]

[% Asset.js("lib/js-cookie/js.cookie-3.0.1.min.js") | $raw %]
<script>
$(document).ready(function() {
    if($('#searchsubmit').length) {
        $(document).on("click", '#searchsubmit', function(e) {
            Cookies.remove("form_serialized", { path: '/'});
            Cookies.remove("form_serialized_limits", { path: '/'});
            Cookies.remove("search_path_code", { path: '/'});
        });
    }
});
</script>
[% PROCESS jsinclude %]
[% IF ( Koha.Preference('OPACUserJS') ) %]
 <script>
        [% Koha.Preference('OPACUserJS') | $raw %]
    </script>
[% END %]
[% IF SCO_login %]
 [% SET SCOUserJS = Koha.Preference('SCOUserJS') %]
 [% IF ( SCOUserJS ) %]
 <script>

            [% SCOUserJS | $raw %]

        </script>
 [% END %]
[% END %]
[% KohaPlugins.get_plugins_opac_js | $raw %]
</body>
</html>
