[% USE Koha %]
[% PROCESS 'html_helpers.inc' %]
[% PROCESS 'patronfields.inc' %]
<!-- cataloging-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">

 <div id="addbooks_search" role="tabpanel" class="tab-pane active">
 <form name="search" action="addbooks.pl">
 <div class="form-title">
 <label class="control-label">Tìm tài liệu</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" type="text" name="q" id="cat_search" placeholder="Tìm kiếm danh mục và nơi lưu trữ" size="40" />
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% INCLUDE 'checkin-search-box.inc' %]
 [% INCLUDE 'renew-search-box.inc' %]
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div><!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation" class="active">
 <a aria-controls="addbooks_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#addbooks_search" role="tab" title="Tìm tài liệu"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Tìm tài liệu</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="circ_search" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Ghi mượn"><i class="fa fa-upload"></i> <span class="tab-title">Ghi mượn</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="checkin_search" class="keep_text" data-toggle="tab" href="#checkin_search" role="tab" title="Ghi Trả"><i class="fa fa-download"></i> <span class="tab-title">Ghi Trả</span></a>
 </li>
 <li role="presentation">
 <a aria-controls="renew_search" class="keep_text" data-toggle="tab" href="#renew_search" role="tab" title="Gia hạn"><i class="fa fa-retweet"></i> <span class="tab-title">Gia hạn</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a title="Search catalog" href="#catalog_search" aria-controls="catalog_search" role="tab" data-toggle="tab" class="keep_text"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Tìm kiếm danh mục</span></a>
 </li>
 [% END %]
 </ul>
</div><!-- /#header_search -->
<!-- /cataloging-search.inc -->
