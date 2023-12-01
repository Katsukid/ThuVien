[% USE Koha %]
[% USE Branches %]
[% IF ( CAN_user_catalogue ) %]
 <!-- catalogue-search-box.inc -->
 [% IF( bs_tab_active ) %]
 <div id="catalog_search" role="tabpanel" class="tab-pane active">
 [% ELSE %]
 <div id="catalog_search" role="tabpanel" class="tab-pane">
 [% END %]
 <form action="/cgi-bin/koha/catalogue/search.pl"  method="get" id="cat-search-block">
 <div class="form-title">
 <label class="control-label">Tìm kiếm danh mục</label>
 </div>

 <div class="form-content">
 [% IF ( Koha.Preference('RetainCatalogSearchTerms') ) %]
 <input class="query form-text head-searchbox form-control" id="search-form" name="q" placeholder="Nhập từ khóa" size="20" title="Nhập thuật ngữ bạn muốn tìm kiếm." type="text" value="[% ms_value | html %]" />
 [% ELSE %]
 <input class="query form-text head-searchbox form-control" id="search-form" name="q" placeholder="Nhập từ khóa" size="20" title="Nhập thuật ngữ bạn muốn tìm kiếm." type="text" />
 [% END %]

 [% IF Koha.Preference('IntranetCatalogSearchPulldown') || Koha.Preference('IntranetAddMastheadLibraryPulldown') %]
 <button type="button" class="form-extra-content-toggle"><i class="fa fa-sliders"></i></button>
 [% END %]
 </div>
 <button type="submit"><i class="fa fa-arrow-right"></i></button>

 <div class="form-extra-content">
 [% IF ( Koha.Preference('IntranetCatalogSearchPulldown') ) %]
 <div>
 <label for="idx">Search index</label>
 [% INCLUDE 'search_indexes.inc' $header_pulldown = 1 %]
 </div>
 [% END %]

 [% IF ( Koha.Preference('IntranetAddMastheadLibraryPulldown') ) %]
 <div>
 <label for="select_library">Thư viện</label>
 <select id="select_library" name="limit">
 <option value="">Tất cả thư viện</option>
 [% PROCESS options_for_libraries prefix => "branch:" libraries => Branches.all( selected => branch_limit ) %]
 </select>
 </div>
 [% END %]
 </div>
 </form>
 </div>
 <!-- /catalogue-search-box.inc -->
[% END %]
