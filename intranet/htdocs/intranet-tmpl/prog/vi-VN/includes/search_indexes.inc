[% USE Koha %]
[% IF refiner %]
 <select class="advsearch" name="idx" id="refiner_idx">
[% ELSE %]
 <select class="advsearch" name="idx" id="idx">
[% END %]
 [% IF ms_kw %]
 <option selected="selected" value="kw">Từ khóa</option>
 [% ELSE %]
 <option value="kw">Từ khóa</option>
 [% END %]
 [% IF ms_kwcommaphr %]
 <option selected="selected" value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ</option>
 [% ELSE %]
 <option value="kw,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ</option>
 [% END %]
 [% IF ms_au %]
 <option selected="selected" value="au">Tác giả</option>
 [% ELSE %]
 <option value="au">Tác giả</option>
 [% END %]
 [% IF ms_aucommaphr %]
 <option selected="selected" value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ tên tác giả</option>
 [% ELSE %]
 <option value="au,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ tên tác giả</option>
 [% END %]
 [% IF ms_cpn %]
 <option selected="selected" value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Tên tập thể</option>
 [% ELSE %]
 <option value="cpn">&nbsp;&nbsp;&nbsp;&nbsp; Tên tập thể</option>
 [% END %]
 [% IF ms_cfn %]
 <option selected="selected" value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Tên hội nghị</option>
 [% ELSE %]
 <option value="cfn">&nbsp;&nbsp;&nbsp;&nbsp; Tên hội nghị</option>
 [% END %]
 [% IF ms_cpncommaphr %]
 <option selected="selected" value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ hội nghị</option>
 [% ELSE %]
 <option value="cpn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ hội nghị</option>
 [% END %]
 [% IF ms_cfncommaphr %]
 <option selected="selected" value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ hội nghị</option>
 [% ELSE %]
 <option value="cfn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ hội nghị</option>
 [% END %]
 [% IF ms_pn %]
 <option selected="selected" value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Cá nhân</option>
 [% ELSE %]
 <option value="pn">&nbsp;&nbsp;&nbsp;&nbsp; Cá nhân</option>
 [% END %]
 [% IF ms_pncommaphr %]
 <option selected="selected" value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ tên cá nhân</option>
 [% ELSE %]
 <option value="pn,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ tên cá nhân</option>
 [% END %]
 [% IF ms_ti %]
 <option selected="selected" value="ti">Nhan đề</option>
 [% ELSE %]
 <option value="ti">Nhan đề</option>
 [% END %]
 [% IF ms_ticommaphr %]
 <option selected="selected" value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ nhan đề</option>
 [% ELSE %]
 <option value="ti,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ nhan đề</option>
 [% END %]
 [% IF ms_se %]
 <option selected="seleced" value="se">&nbsp;&nbsp;&nbsp;&nbsp; Nhan đề tùng thư</option>
 [% ELSE %]
 <option value="se">&nbsp;&nbsp;&nbsp;&nbsp; Nhan đề tùng thư</option>
 [% END %]
 [% IF ms_su %]
 <option selected="selected" value="su">Chủ đề</option>
 [% ELSE %]
 <option value="su">Chủ đề</option>
 [% END %]
 [% IF ms_sucommaphr %]
 <option selected="selected" value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ chủ đề</option>
 [% ELSE %]
 <option value="su,phr">&nbsp;&nbsp;&nbsp;&nbsp; Cụm từ chủ đề</option>
 [% END %]
 [% IF ( expanded_options ) %]
 [% IF ms_sudashbr %]
 <option selected="selected" value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Chủ đề và thuật ngữ rộng hơn</option>
 [% ELSE %]
 <option value="su-br">&nbsp;&nbsp;&nbsp;&nbsp; Chủ đề và thuật ngữ rộng hơn</option>
 [% END %]
 [% IF ms_sudashna %]
 <option selected="selected" value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Chủ đề và thuật ngữ hẹp hơn</option>
 [% ELSE %]
 <option value="su-na">&nbsp;&nbsp;&nbsp;&nbsp; Chủ đề và thuật ngữ hẹp hơn</option>
 [% END %]
 [% IF ms_sudashrl %]
 <option selected="selected" value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Chủ đề và thuật ngữ liên quan</option>
 [% ELSE %]
 <option value="su-rl">&nbsp;&nbsp;&nbsp;&nbsp; Chủ đề và thuật ngữ liên quan</option>
 [% END %]
 [% END %]
 [% IF ms_bc %]
 <option selected="selected" value="bc">Đăng ký cá biệt</option>
 [% ELSE %]
 <option value="bc">Đăng ký cá biệt</option>
 [% END %]
 [% IF ms_locationcommawrdl %]
 <option selected="selected" value="location,wrdl" title="Enter location code value for search">Shelving location (code)</option>
 [% ELSE %]
 <option value="location,wrdl" title="Enter location code value for search">Shelving location (code)</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_identcommaphr %]
 <option selected="selected" value="ident,phr">Số tiêu chuẩn</option>
 [% ELSE %]
 <option value="ident,phr">Số tiêu chuẩn</option>
 [% END %]
 [% ELSE %]
 [% IF ms_ident %]
 <option selected="selected" value="ident">Số tiêu chuẩn</option>
 [% ELSE %]
 <option value="ident">Số tiêu chuẩn</option>
 [% END %]
 [% END %]
 [% IF ms_nb %]
 <option selected="selected" value="nb">&nbsp;&nbsp;&nbsp;&nbsp; Số ISBN</option>
 [% ELSE %]
 <option value="nb">&nbsp;&nbsp;&nbsp;&nbsp; Số ISBN</option>
 [% END %]
 [% IF ms_ns %]
 <option selected="selected" value="ns">&nbsp;&nbsp;&nbsp;&nbsp; Số ISSN</option>
 [% ELSE %]
 <option value="ns">&nbsp;&nbsp;&nbsp;&nbsp; Số ISSN</option>
 [% END %]
 [% IF ( Koha.Preference('IntranetNumbersPreferPhrase') ) %]
 [% IF ms_callnumcommaphr %]
 <option selected="selected" value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Ký hiệu phân loại</option>
 [% ELSE %]
 <option value="callnum,phr">&nbsp;&nbsp;&nbsp;&nbsp; Ký hiệu phân loại</option>
 [% END %]
 [% ELSE %]
 [% IF ms_callnum %]
 <option selected="selected" value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Ký hiệu phân loại</option>
 [% ELSE %]
 <option value="callnum">&nbsp;&nbsp;&nbsp;&nbsp; Ký hiệu phân loại</option>
 [% END %]
 [% END %]
 [% IF ms_lncommartrn %]
 <option selected="selected" value="ln,rtrn">Ngôn ngữ</option>
 [% ELSE %]
 <option value="ln,rtrn">Ngôn ngữ</option>
 [% END %]
 [% IF ms_nt %]
 <option selected="selected" value="nt">Ghi chú/Bình luận</option>
 [% ELSE %]
 <option value="nt">Ghi chú/Bình luận</option>
 [% END %]
 [% IF (marcflavour != 'UNIMARC' ) %]
 [% IF ms_curriculum %]
 <option selected="selected" value="curriculum">Chương trình đào tạo</option>
 [% ELSE %]
 <option value="curriculum">Chương trình đào tạo</option>
 [% END %]
 [% END %]
 [% IF ms_pb %]
 <option selected="selected" value="pb">Nhà xuất bản</option>
 [% ELSE %]
 <option value="pb">Nhà xuất bản</option>
 [% END %]
 [% IF ms_pl %]
 <option selected="selected" value="pl">Nơi xuất bản</option>
 [% ELSE %]
 <option value="pl">Nơi xuất bản</option>
 [% END %]

 [%# Use non-normalized st-year instead of st-numeric, %]
 [%# since pubdate can include 'u' to signify unknown %]
 [%# dates. See "Legal Characters" at: %]
 [%# http://www.loc.gov/marc/bibliographic/bd008a.html %]
 [%# This search is also for date ranges due to the %]
 [%# special Zebra r=r CCL mapping for 'yr' %]
 [% IF ms_yrcommastdashyear %]
 <option selected="selected" value="yr,st-year">Publication date (yyyy-yyyy)</option>
 [% ELSE %]
 <option value="yr,st-year">Publication date (yyyy-yyyy)</option>
 [% END %]
 [% IF ms_acqdatecommastdashdatedashnormalized %]
 <option selected="selected" value="acqdate,st-date-normalized">Ngày bổ sung (yyyy-mm-dd)</option>
 [% ELSE %]
 <option value="acqdate,st-date-normalized">Ngày bổ sung (yyyy-mm-dd)</option>
 [% END %]
</select>
